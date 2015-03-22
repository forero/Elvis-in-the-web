Datos de Vacios
============================

- Archivos halos*.dat contienen catalogos de halos en formato del código Halos-Distance.
- Archivos distances*.dat contienen distancias de cada halo a la celda más cercana que pertenece al vacío más cercano. El formato es:

  Distancia	IdVoid		i	j	k

  donde Distancia, i, j y k son la distancia y los índices de la celda más cercana del vacío.
- Dentro de cada carpeta vacios1, ..., vacios20 están los archivos de vacíos para cada caja. Los archivos void_?.dat contienen los ids de las
celdas que pertenencen a ese vacío. Los archivos void_?.ngb contiene los índices de los vacíos vecinos.
- Dentro de estas carpetas también están los archivos:
  - void_regions.dat: contiene índice de todos los vacíos, número de celdas del vacío y radio esférico efectivo.
  - DC.dat: contiene las coordenadas comóviles y el id de la celda que pertenece al mínimo de densidad de cada vacío. Este valor puede
  tomarse como el centro de cada vacío (Esta es la aproximación en el paper de Vacíos.)
  - FA.dat: contiene las coordenadas comóviles y el id de la celda que pertenece al mínimo de FA de cada vacío. Este valor también podría 
  tomarse como un valor alternativo al centro de cada vacío.

