cmake_minimum_required (VERSION 2.6)
project (Neural)

file(GLOB NEURAL_SRC
	"*.hpp"
    "*.cpp"
)

add_executable(Neural ${NEURAL_SRC})