cmake_minimum_required (VERSION 2.6)
project (Neural)

file(GLOB NEURAL_SRC
	"src/*.hpp"
    "src/*.cpp"
)

add_executable(Neural ${NEURAL_SRC})