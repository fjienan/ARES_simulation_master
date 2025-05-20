import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/fideow/ROBOCON25_simulation-master/src/install/omni_mpc_controller'
