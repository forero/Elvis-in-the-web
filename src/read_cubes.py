from ast import literal_eval
from struct import *
import numpy as np
import matplotlib.pyplot as plt
from pylab import *

def read_CIC_scalar(filename):
    f = open(filename, "rb")
    dumb = f.read(38)

    dumb = f.read(4)
    n_x = f.read(4)
    n_y = f.read(4)
    n_z = f.read(4)
    nodes = f.read(4)
    x0 = f.read(4)
    y0 = f.read(4)
    z0 = f.read(4)
    dx = f.read(4)
    dy = f.read(4)
    dz = f.read(4)
    dumb = f.read(4)

    n_x = (unpack('i', n_x))[0]
    n_y = (unpack('i', n_y))[0]
    n_z = (unpack('i', n_z))[0]
    nodes = (unpack('i', nodes))[0]
    dx = (unpack('f', dx))[0]
    dy = (unpack('f', dy))[0]
    dz = (unpack('f', dz))[0]
    x0 = (unpack('f', x0))[0]
    y0 = (unpack('f', y0))[0]
    z0 = (unpack('f', z0))[0]
    print n_x, n_y, n_z, nodes, dx, dy, dz

    total_nodes = n_x * n_y *n_z
    dumb = f.read(4)
    array_data = f.read(total_nodes*4)
    dumb = f.read(4)
    format_s = str(total_nodes)+'f'
    array_data = unpack(format_s, array_data)
    f.close()
    array_data  = np.array(array_data)
    array_data.resize(n_z,n_y,n_x)
    array_data = array_data.transpose()
    return array_data


def read_CIC_vector(filename):
    f = open(filename, "rb")
    dumb = f.read(38)

    dumb = f.read(4)
    n_x = f.read(4)
    n_y = f.read(4)
    n_z = f.read(4)
    nodes = f.read(4)
    x0 = f.read(4)
    y0 = f.read(4)
    z0 = f.read(4)
    dx = f.read(4)
    dy = f.read(4)
    dz = f.read(4)
    dumb = f.read(4)

    n_x = (unpack('i', n_x))[0]
    n_y = (unpack('i', n_y))[0]
    n_z = (unpack('i', n_z))[0]
    nodes = (unpack('i', nodes))[0]
    dx = (unpack('f', dx))[0]
    dy = (unpack('f', dy))[0]
    dz = (unpack('f', dz))[0]
    x0 = (unpack('f', x0))[0]
    y0 = (unpack('f', y0))[0]
    z0 = (unpack('f', z0))[0]
    print n_x, n_y, n_z, nodes, dx, dy, dz

    total_nodes = 3 * n_x * n_y *n_z
    dumb = f.read(4)
    array_data = f.read(total_nodes*4)
    dumb = f.read(4)
    format_s = str(total_nodes)+'f'
    array_data = unpack(format_s, array_data)
    f.close()
    array_data  = np.array(array_data)
    array_data.resize(n_z,n_y,n_x,3)
    vec = array_data[0,0,0,:]
    vec = array_data[0,0,1,:]
    array_data = array_data.transpose()
    #final shape is [3,n_x,n_y,n_z]
    return array_data



def test_cut_plot():
    filein="/Users/forero/Dropbox/Elvis-in-the-web/data/GVD_F09_1001_000_z125_box14_009.s2.00.eigen_1"
    eigen1 = read_CIC_scalar(filein)
    filein="/Users/forero/Dropbox/Elvis-in-the-web/data/GVD_F09_1001_000_z125_box14_009.s2.00.eigen_2"
    eigen2 = read_CIC_scalar(filein)
    filein="/Users/forero/Dropbox/Elvis-in-the-web/data/GVD_F09_1001_000_z125_box14_009.s2.00.eigen_3"
    eigen3 = read_CIC_scalar(filein)

    rc('text', usetex=True)
    rc('font', family='serif')

    print amax(eigen1[50,:,:]+eigen2[50,:,:]+eigen3[50,:,:])
    print amin(eigen1[50,:,:]+eigen2[50,:,:]+eigen3[50,:,:])
    plt.imshow(log10(eigen1[50,:,:].T+eigen2[50,:,:].T+eigen3[50,:,:].T+1))
#plt.plot(mu_x_range[:-1], histo_mu_x, label="$e_{3}\cdot \hat{x}$")


    plt.xlabel("$Y$")
    plt.ylabel("$Z$")
    plt.savefig("slice_eigen_1.pdf")


test_cut_plot()

