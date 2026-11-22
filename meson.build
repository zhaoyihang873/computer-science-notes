project(
  'computer-science-notes',
  'c',
  default_options: ['c_std=c99'],
)

chapter_python = import('python').find_installation()
scan_chapter_sources = '''
from pathlib import Path
import re
import sys

chapter = Path(sys.argv[1])
source_groups = (
    ('examples', r'example([0-9]+)[.]c', 'ex'),
    ('exercises', r'((?:ex|exercise)[0-9]+)[.]c', 'exercises_'),
)
for directory, pattern, prefix in source_groups:
    for source in sorted((chapter / directory).glob('*.c')):
        match = re.fullmatch(pattern, source.name)
        if match and source.is_file():
            print(f'{prefix}{match[1]}:{directory}/{source.name}')
'''

subdir('K&R')
subdir('CSAPP')
