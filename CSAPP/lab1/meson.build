datalab_options = ['c_std=gnu99', 'optimization=0']
datalab_c_args = ['-fwrapv', '-fno-strict-aliasing']
datalab_math = meson.get_compiler('c').find_library('m')

executable(
  'datalab_btest',
  'bits.c', 'btest.c', 'decl.c', 'tests.c',
  c_args: datalab_c_args,
  dependencies: datalab_math,
  override_options: datalab_options,
)
executable(
  'datalab_fshow',
  'fshow.c',
  c_args: datalab_c_args,
  override_options: datalab_options,
)
executable(
  'datalab_ishow',
  'ishow.c',
  c_args: datalab_c_args,
  override_options: datalab_options,
)
