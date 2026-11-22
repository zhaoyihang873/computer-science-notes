python = import('python').find_installation()
scan_sources = '''
from pathlib import Path
import re
import sys

directory = Path(sys.argv[1])
pattern = re.compile(sys.argv[2])
for source in sorted(directory.glob('*.c')):
    if source.is_file() and pattern.fullmatch(source.name):
        print(source.name)
'''

source_groups = {
  'examples': ['example[0-9]+[.]c', 'kr_ch1_'],
  'exercises': ['(?:ex|exercise)[0-9]+[.]c', 'kr_ch1_exercises_'],
}

foreach directory, group : source_groups
  sources = run_command(
    python,
    '-c',
    scan_sources,
    meson.current_source_dir() / directory,
    group[0],
    check: true,
  ).stdout().split()

  foreach source : sources
    name = source.split('.')[0].replace('example', 'ex')
    executable(group[1] + name, directory / source)
  endforeach
endforeach
