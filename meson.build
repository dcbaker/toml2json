project(
  'toml2json',
  'cpp',
  version : '0.0.1',
  meson_version : '>= 0.60',
  default_options : ['cpp_std=c++17']
)

dep_tomlpp = dependency('tomlplusplus', version : ['>= 3.0', '< 4.0'])
dep_fs = dependency('', required : false)

cpp = meson.get_compiler('cpp')
if cpp.get_id() == 'gcc'
  dep_fs = cpp.find_library('stdc++fs', required : false)
elif cpp.get_id() == 'clang'
  dep_fs = cpp.find_library('c++fs', required : false)
endif

toml2json = executable(
  'toml2json',
  'src/main.cpp',
  dependencies : [dep_tomlpp, dep_fs],
  install : true,
)

meson.override_find_program('toml2json', toml2json)
