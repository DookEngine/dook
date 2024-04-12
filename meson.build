project(
  'dook',
  'cpp',
  version: '0.1',
  default_options: ['warning_level=3', 'cpp_std=c++20'],
)

if host_machine.system() == 'windows'
  add_project_arguments(['-DCANCEL_SDL_MAIN'], language: 'cpp')
endif

subdir('src/')
subdir('src/entities')
subdir('src/services')
subdir('src/sdl')
subdir('src/game')
subdir('src/jparser')

# Entities Dependency

libentities = static_library(
  'entities',
  entities_files,
  include_directories: entities_includes,
)

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

sdl2_dep = dependency('sdl2')
sdl2_main_dep = dependency(
  'sdl2main',
  required: host_machine.system() == 'windows',
)
sdl2_img_dep = dependency('sdl2_image')

libsdl = static_library(
  'sdl',
  sdl_files,
  include_directories: sdl_includes,
  dependencies: [
    libentities_dep,
    libservices_dep,
    sdl2_dep,
    sdl2_main_dep,
    sdl2_img_dep,
  ],
)

libsdl_dep = declare_dependency(
  include_directories: sdl_includes,
  link_with: libsdl,
)

# JSON Parser dependency

json_dep = dependency('nlohmann_json')

libjparser = static_library(
  'jparser',
  jparser_files,
  include_directories: jparser_includes,
  dependencies: [libentities_dep, libservices_dep, json_dep],
)

libjparser_dep = declare_dependency(
  include_directories: jparser_includes,
  link_with: libjparser,
)

# Game dependency, this hopefully wraps everything together.
libgame = static_library(
  'game',
  game_files,
  include_directories: game_includes,
  dependencies: [
    libentities_dep,
    libservices_dep,
    sdl2_dep,
    sdl2_main_dep,
    sdl2_img_dep,
    libsdl_dep,
  ],
)

libgame_dep = declare_dependency(
  include_directories: game_includes,
  link_with: libgame,
)

executable(
  'dook',
  main_file,
  win_subsystem: 'windows',
  dependencies: [
    libentities_dep,
    libservices_dep,
    libsdl_dep,
    libjparser_dep,
    libgame_dep,
    sdl2_dep,
    sdl2_img_dep,
    json_dep,
  ],
)
