import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/furry/Desktop/ARES_simulation_master/install/omni_mpc_controller'
