import os,sys,shutil
from distutils.core import setup, Extension
from Cython.Build import cythonize

main_file = "share.c"

def install(main_file):
	nama = main_file.split(".")[0]
	setup(name = main_file,ext_modules = [Extension(nama, [main_file])],script_args = ['build_ext', '--inplace', '--force', '-j 5'])
	if os.path.exists(main_file):
		try: shutil.rmtree('build/')
		except:0
		try: os.remove(main_file)
		except:0
	else:
		print("ketik 'python -m pip install -r bahan.txt")

install(main_file)
