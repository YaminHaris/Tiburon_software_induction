import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yami/CODE/Tiburon Software Induction/install/turtle_controller'
