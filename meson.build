project(
  'dook',
  'cpp',
  version: '0.1',
  default_options: ['warning_level=3', 'cpp_std=c++20'],
)

subdir('src/')
subdir('src/entities')
subdir('src/services')
subdir('src/sdl')

# Entities Dependency

libentities = static_library('entities', entities_files, include_directories: entities_includes)

libentities_dep = declare_dependency(
  include_directories: entities_includes,
  link_with: libentities,
)

# Core Services Dependency
libservices = static_library(
  'services',
  services_files,
  include_directories: services_includes,
  dependencies: [libentities_dep],
)

libservices_dep = declare_dependency(
  include_directories: services_includes,
  link_with: libservices,
)

# SDL Wrapper Depenedency

libsdl = static_library(
  'sdl',
  sdl_files,
  include_directories: sdl_includes,
  dependencies: [libentities_dep, libservices_dep],
)

libsdl_dep = declare_dependency(
  include_directories: sdl_includes,
  link_with: libsdl,
)


executable('dook', main_file, dependencies: [libentities_dep, libservices_dep, libsdl_dep])
