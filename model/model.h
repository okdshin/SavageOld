#ifndef SAVAGE_MODEL_MODEL_H
#define SAVAGE_MODEL_MODEL_H
//20140412
#include <savage/static_assert.h>
#include <savage/shader/name.h>
namespace savage { 
	namespace models {
		namespace traits {
		}// namespace traits
		/*
		namespace policy {
			template<typename Model, typename VertexArray, 
				typename TextureCoordinateArray>
			struct construct {
				static Model call(const VertexArray& vertex_array,
						const TextureCoordinateArray& texture_coordinate_array) {
					SAVAGE_NOT_IMPLEMENTED_STATIC_ASSERT;
				}
			};
		}// namespace policy
		template<typename Model, typename VertexArray, 
			typename TextureCoordinateArray>
		void construct(const VertexArray& vertex_array,
				const TextureCoordinateArray& texture_coordinate_array) {
			return savage::shader::models::policy::
				construct<Model, VertexArray, TextureCoordinateArray>::call(
						vertex_array, texture_coordinate_array);
		}
		*/
		namespace policy {
			template<typename Model>
			struct draw {
				static void call(const Model& model) {
					model.draw();
				}
			};
		}// namespace policy
		template<typename Model>
		void draw(const Model& model) {
			savage::models::policy::draw<Model>::call(model);
		}
		namespace adapted { namespace savage {
			class model {
			public:
				model(){}
				model(const std::vector<glm::vec3>& vertex_array) : 
					vertex_array_(vertex_array) {
					glGenVertexArrays(1, &vertex_array_handle_);
					glGenBuffers(1, &vertex_buffer_handle_);
				}
				bool load_from_obj_file(const std::string& filename) {
					const char* path = filename.c_str();
					printf("Loading OBJ file %s...\n", path);

					std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
					std::vector<glm::vec3> temp_vertices; 
					std::vector<glm::vec2> temp_uvs;
					std::vector<glm::vec3> temp_normals;

					FILE * file = fopen(path, "r");
					if( file == NULL ){
						printf("Impossible to open the file !");
						getchar();
						return false;
					}
					while( 1 ){
						char lineHeader[128];
						// read the first word of the line
						int res = fscanf(file, "%s", lineHeader);
						if (res == EOF)
							break; // EOF = End Of File. Quit the loop.
						// else : parse lineHeader
						if ( strcmp( lineHeader, "v" ) == 0 ){
							glm::vec3 vertex;
							fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
							temp_vertices.push_back(vertex);
						}else if ( strcmp( lineHeader, "vt" ) == 0 ){
							glm::vec2 uv;
							fscanf(file, "%f %f\n", &uv.x, &uv.y );
							uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
							temp_uvs.push_back(uv);
						}else if ( strcmp( lineHeader, "vn" ) == 0 ){
							glm::vec3 normal;
							fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
							temp_normals.push_back(normal);
						}else if ( strcmp( lineHeader, "f" ) == 0 ){
							std::string vertex1, vertex2, vertex3;
							unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
							int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
							if (matches != 9){
								printf("File can't be read by our simple parser :-( Try exporting with other options\n");
								return false;
							}
							vertexIndices.push_back(vertexIndex[0]);
							vertexIndices.push_back(vertexIndex[1]);
							vertexIndices.push_back(vertexIndex[2]);
							uvIndices    .push_back(uvIndex[0]);
							uvIndices    .push_back(uvIndex[1]);
							uvIndices    .push_back(uvIndex[2]);
							normalIndices.push_back(normalIndex[0]);
							normalIndices.push_back(normalIndex[1]);
							normalIndices.push_back(normalIndex[2]);
						}else{
							// Probably a comment, eat up the rest of the line
							char stupidBuffer[1000];
							fgets(stupidBuffer, 1000, file);
						}
					}
					// For each vertex of each triangle
					for( unsigned int i=0; i<vertexIndices.size(); i++ ){

						// Get the indices of its attributes
						unsigned int vertexIndex = vertexIndices[i];
						//unsigned int uvIndex = uvIndices[i];
						//unsigned int normalIndex = normalIndices[i];
						
						// Get the attributes thanks to the index
						glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
						//glm::vec2 uv = temp_uvs[ uvIndex-1 ];
						//glm::vec3 normal = temp_normals[ normalIndex-1 ];
						
						// Put the attributes in buffers
						vertex_array_.push_back(vertex);
						//out_uvs     .push_back(uv);
						//out_normals .push_back(normal);
					
					}

					return true;
				}

				~model() {
					glDeleteBuffers(1, &vertex_buffer_handle_);
					glDeleteVertexArrays(1, &vertex_array_handle_);
				}
				template<typename Program, typename Name>
				void initialize(const Program& program, const Name& name) {
					glBindVertexArray(vertex_array_handle_);
					glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_handle_);
					glBufferData(GL_ARRAY_BUFFER, 
							vertex_array_.size() * sizeof(glm::vec3), 
							vertex_array_.data(), GL_STATIC_DRAW);
					glBindAttribLocation(program.get_handle(), 0, 
							::savage::shader::names::get_pointer(name));
				}
				void draw() const {
					glEnableVertexAttribArray(0);
					glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_handle_);
					glVertexAttribPointer(
						0,                  // attribute
						3,                  // size
						GL_FLOAT,           // type
						GL_FALSE,           // normalized?
						0,                  // stride
						(void*)0            // array buffer offset
					);
					glDrawArrays(GL_TRIANGLES, 0, vertex_array_.size());
					glDisableVertexAttribArray(0);
				}
			private:
				GLuint vertex_array_handle_;
				GLuint vertex_buffer_handle_;
				std::vector<glm::vec3> vertex_array_;
			};
		}// namespace savage
		}// namespace adapted
	}// namespace models
	using savage::models::adapted::savage::model;
}// namespace savage
#endif //SAVAGE_MODEL_MODEL_H
