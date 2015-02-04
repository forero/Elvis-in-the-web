# This is how the first set of data was created on bachue. 
# This has to be replaced by a Makefile.

./smooth_bolshoi.x /home/forero/work/data/ELVIS/fullboxes/GVD_F09_1001_000_z125_box14_009 -n 128
./smooth_bolshoi.x -d GVD_F09_1001_000_z125_box14_009 -s 2.0
./smooth_bolshoi.x -d GVD_F09_1001_000_z125_box14_009 -s 2.0 -eigenvector