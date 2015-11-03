{
  'targets': [
    {
      'target_name': 'app',
      'sources': [
        'src/main.cc',
        'src/common.cc',
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")'
      ],
    }
  ]
}