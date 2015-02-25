IN_PATH=/home/forero/work/data/ELVIS/fullboxes/
OUT_PATH=/home/forero/work/data/ELVIS/Tweb/
EXEC_FILE=/home/forero/work/TV-Web/src/./smooth_bolshoi.x
SNAPS =  $(notdir $(wildcard $(IN_PATH)GVD_F09_1001_000_z125*009))
TARGETS = $(subst 009,009.CIC,$(SNAPS))


all: $(TARGETS)
	echo "done"


$(TARGETS) : %.CIC: $(IN_PATH)%
	$(EXEC_FILE)  $< -n 128 
	$(EXEC_FILE) -d $* -s 2.0
	$(EXEC_FILE) -d $* -s 2.0 -eigenvector

clean:
	ls -l $(SNAPS)
	rm -f $(TARGETS)