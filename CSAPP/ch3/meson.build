chapter_sources = run_command(
  chapter_python,
  '-c',
  scan_chapter_sources,
  meson.current_source_dir(),
  check: true,
).stdout().split()

foreach entry : chapter_sources
  target = entry.split(':')
  executable('csapp_ch3_' + target[0], target[1])
endforeach
