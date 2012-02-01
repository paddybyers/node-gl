
{
  'variables': {
      'node_module_sources': [
          'node-gl.cpp',
          'glbindings/glbind.cpp',
          'glesbindings/glesbind.cpp',
          'glubindings/glubind.cpp',
          'glutbindings/glutbind.cpp',
          'imageloader.cpp',
          'utils.cpp',
      ],
      'node_root': '/Users/paddy/data/work/dev/nodejs-0.6/',
  },
  'targets': [
    {
      'target_name': 'node-gl',
      'product_name': 'node-gl',
      'type': 'loadable_module',
      'product_prefix': '',
      'product_extension':'node',
      'sources': [
        '<@(node_module_sources)',
      ],
      'defines': [
        'BUILD_GL_BINDINGS=1',
        'BUILD_GLES_BINDINGS=1',
        'BUILD_GLU_BINDINGS=1',
        'BUILD_GLUT_BINDINGS=1',
        'PLATFORM="<(OS)"',
        '_LARGEFILE_SOURCE',
        '_FILE_OFFSET_BITS=64',
      ],
      'conditions': [
        [ 'OS=="mac"', {
          'libraries': [
            '-undefined dynamic_lookup',
          ],
          'xcode_settings': {
            'OTHER_LDFLAGS': [
              '-undefined dynamic_lookup',
              '-framework OpenGL',
              '-framework GLUT',
            ]
          },
          'include_dirs': [
             'include/',
             '<@(node_root)/node/src',
             '<@(node_root)/node/deps/v8/include',
             '<@(node_root)/node/deps/uv/include',
          ],
        }],
        [ 'OS=="win"', {
          'defines': [
            'PLATFORM="win32"',
            '_WINDOWS',
            '__WINDOWS__', # ltdl
            'BUILDING_NODE_EXTENSION'
          ],
          'libraries': [ 
              'node.lib',
			  'zlib.lib'
          ],
          'include_dirs': [
             'include',
          ],
          'msvs_settings': {
            'VCLinkerTool': {
              'AdditionalOptions': [
                # https://github.com/mapnik/node-mapnik/issues/74
                '/FORCE:MULTIPLE'
              ],
              'AdditionalLibraryDirectories': [
              ],
            },
          },
        },
      ], # windows
      ] # condition
    }, # targets
  ],
}