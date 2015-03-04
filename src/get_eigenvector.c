#include <stdio.h>
#include <stdlib.h>
#define USAGE "./get_eigenvector.x filename pos_x pos_y pos_z"
/*
   USAGE: ./get_eigenvector.c filename
   AUTHOR: Jaime Forero-Romero 
   DESCRIPTION:
   Gets the corresponding eigenvector at the positions pos_x, pos_y, poz_z
   Loads a 3Dimensional grid into a 3D array.

   NOTES:
   n_x, n_y, n_z is the grid size
   x_0, y_0, z_0 is the posiion of the cell for the grid(i,j,k) element in Mpc/h
   dx,dy,z is the grid size in Mpc/h
   
   grid[n] runs over 3,x,y,z in space, following fortran array conventions
   for memory handling where the "3"refers to the vector components.

   i.e. the component 0 at the point grid(i,j,k) corresponds to
   grid[0 + 3 * (i + N_X * (j + N_Y * k))] where N_X is the grid
   dimension size in x and N_Y is the grid dimension size in y (i,j,k
   start at 0). 
*/

#define FLOAT float
int main(int argc, char **argv){
  FILE *in;
  FLOAT *grid;
  int dumb;
  char line[30];
  long long i;
  long long n_total;
  int n_x, n_y, n_z;
  int n_nodes;
  float dx, dy, dz, x_0, y_0, z_0;
  FLOAT max_val, min_val;
  float pos_x, pos_y, pos_z;
  int id_i, id_j, id_k;

  if(argc!=5){
    fprintf(stderr, "USAGE: %s\n", USAGE);
    exit(1);
  }
  

  if(!(in=fopen(argv[1], "r"))){
    fprintf(stderr, "Problem opening file %s\n", argv[1]);
    exit(1);
  }

  pos_x = atof(argv[2]);
  pos_y = atof(argv[3]);
  pos_z = atof(argv[4]);

  fread(&dumb,sizeof(int),1,in);
  fread(line,sizeof(char)*30,1,in);
  fread(&dumb,sizeof(int),1,in);

  fread(&dumb,sizeof(int),1,in);
  fread(&n_x,sizeof(int),1,in);    
  fread(&n_y,sizeof(int),1,in);    
  fread(&n_z,sizeof(int),1,in);    
  fread(&n_nodes,sizeof(int),1,in);    
  fread(&x_0,sizeof(float),1,in);    
  fread(&y_0,sizeof(float),1,in);    
  fread(&z_0,sizeof(float),1,in);    
  fread(&dx,sizeof(float),1,in);    
  fread(&dy,sizeof(float),1,in);    
  fread(&dz,sizeof(float),1,in);    
  fread(&dumb,sizeof(int),1,in);

  n_total = n_x * n_y * n_z;
  if(!(grid=malloc(3 * n_total * sizeof(FLOAT)))){
    fprintf(stderr, "problem with array allocation\n");
    exit(1);
  }
  
  fread(&dumb,sizeof(int),1,in);
  fread(&(grid[0]),sizeof(FLOAT), n_nodes*3, in);
  fread(&dumb,sizeof(int),1,in);  
#ifdef VERBOSE
  fprintf(stderr, "Nx Ny Nz : %d %d %d %d\n", n_x, n_y, n_z, n_nodes);
  fprintf(stderr, "x_0 y_0 z_0 : %g %g %g\n", x_0, y_0, z_0);
  fprintf(stderr, "dx dy dz : %g %g %g\n", dx, dy, dz);
#endif
  fclose(in);

  id_i = (int)(pos_x/(dz));
  id_j = (int)(pos_y/(dz));
  id_k = (int)(pos_z/(dz));
	  

  if((id_i<0)||(id_i)>=n_x||((id_j<0)||(id_j)>=n_x) || ((id_k<0)||(id_k)>=n_x)){
    fprintf(stderr, "id outside bounds\n");    
    exit(1);
  }

#ifdef VERBOSE
  fprintf(stderr, "requested pos %g %g %g\n", pos_x, pos_y, pos_z);
  fprintf(stderr, "corresponding id %d %d %d\n", id_i, id_j, id_k);
#endif 

  fprintf(stdout, "%g %g %g \n", 
	  grid[0 + 3*(id_i + n_x * (id_j + n_y * id_k))],
	  grid[1 + 3*(id_i + n_x * (id_j + n_y * id_k))],
	  grid[2 + 3*(id_i + n_x * (id_j + n_y * id_k))]);


  return 0;
}
