{
  'targets': [
    {
      'target_name': 'mouse',
      'sources': [
        'src/main.cc',
        'src/common.cc',
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")'
      ],
      'conditions': [
        ['OS=="win"', {
          'sources': [
            'src/mouse_win.cc'
          ],
          'msvs_disabled_warnings': [],
        }],
      ],
    }
  ]
}