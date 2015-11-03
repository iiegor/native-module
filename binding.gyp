{
  'targets': [
    {
      'target_name': 'app',
      'sources': [
        'src/main.cc',
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")'
      ],
      'conditions': [
        ['OS=="win"', {
          'sources': [
            'src/app_win.cc',
          ],
          'libraries': [
            '-lole32.lib',
            '-lshell32.lib',
          ],
        }]
      ],
    }
  ]
}