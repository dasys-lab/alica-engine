project('alica_common_config', 'cpp',
  version : '0.0.0',
  meson_version: '>=0.54.0',
  license : 'MPL-2.0')

project_description = 'A library to define debug levels for Output.'


project_headers = [
  'include/alica_common_config/common_defines.h',  
  'include/alica_common_config/debug_output.h'
]

project_source_files = [
]

project_test_files = [
]

build_args = [
]


# ===================================================================

# ======
# Target
# ======

public_headers = include_directories('include')

build_args += [
  '-DPROJECT_NAME=' + meson.project_name(),
  '-DPROJECT_VERSION=' + meson.project_version(),
]

project_target = library(
  meson.project_name(),
  project_source_files,
  c_args : build_args,
  include_directories : public_headers,
)


# =======
# Project
# =======

# Make this library usable as a Meson subproject.
project_dep = declare_dependency(
  include_directories: public_headers,
  link_with : project_target,
  version : meson.project_version(),
)
meson.override_dependency(meson.project_name(), project_dep)

# ==========
# Unit Tests
# ==========

