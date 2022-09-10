cmake_minimum_required(VERSION 3.4..3.24)

project(emblem VERSION "1.0.0" LANGUAGES CXX)

# --------------
# ---- GLFW ----
# --------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw)

# --------------
# ---- GLM ----
# --------------
add_subdirectory(lib/glm)

# ----------------
# ---- Vulkan ----
# ----------------
find_package(Vulkan REQUIRED)

# ----------------
# ---- spdlog ----
# ----------------
add_subdirectory(lib/spdlog)

# ----------------------
# ---- scikit-build ----
# ----------------------

if(SKBUILD)
  # Scikit-Build does not add your site-packages to the search path
  # automatically, so we need to add it _or_ the pybind11 specific directory
  # here.
  execute_process(
    COMMAND "${PYTHON_EXECUTABLE}" -c
            "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE _tmp_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE COMMAND_ECHO STDOUT)
  list(APPEND CMAKE_PREFIX_PATH "${_tmp_dir}")
endif()

# Now we can find pybind11
find_package(pybind11 CONFIG REQUIRED)

file(GLOB emblem_SRC
  "src/*.cpp"
)

pybind11_add_module(_emblem MODULE ${emblem_SRC})

target_compile_features(_emblem PRIVATE cxx_std_17)
target_compile_definitions(_emblem PRIVATE VERSION_INFO=${PROJECT_VERSION})
target_link_libraries(_emblem PRIVATE glfw glm spdlog::spdlog ${Vulkan_LIBRARIES})
target_include_directories(_emblem PUBLIC ${Vulkan_INCLUDE_DIR})

install(TARGETS _emblem DESTINATION .)