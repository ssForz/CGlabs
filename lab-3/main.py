import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
from matplotlib.widgets import Slider
from matplotlib.colors import LightSource



# vs = np.array([0,0,0],[0.5,2,0],[2,0.5,0],[0,0,5],[0.5,2,5],[2,0.5,5])
savepoly = [[[0,0,0],[0,0,5],[0.5,2,5]], [[0,0,0],[0.5,2,5],[0.5,2,0]], [[0,0,0],[0,0,5],[2,0.5,5]],[[0,0,0],[2,0.5,5],[2,0.5,0]]]
poly3d = []

def approx_hyperb(num_faces):
    t = np.linspace(0.5 , 2, num_faces)
    h = np.linspace(0, 5, num_faces)
    savex = 0.5;
    savey = 2;
    for i in t:
        poly3d.append([[0,0,0],[savex,savey,0],[i,1/i,0]])
        poly3d.append([[0,0,5],[savex,savey,5],[i,1/i,5]])
        savex = i;
        savey = 1/i;
    t, h = np.meshgrid(t, h)
    x = t
    y = 1/t
    z = h
    return x, y, z


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


faces_slider_ax = plt.axes([0.15, 0.1, 0.65, 0.03])
faces_slider = Slider(faces_slider_ax, 'Уровень детализации', 3, 100, valinit=5, valstep=1)
check_slider_ax = plt.axes([0.15, 0.05, 0.65, 0.03])
check_slider = Slider(check_slider_ax, 'Линии', 0, 1, valinit=0, valstep=1)
# ls = LightSource(azdeg=315, altdeg=45)

def update(val):
    global poly3d
    poly3d.clear()
    poly3d.append(savepoly[0])
    poly3d.append(savepoly[1])
    poly3d.append(savepoly[2])
    poly3d.append(savepoly[3])
    num_faces = int(faces_slider.val)
    x, y, z = approx_hyperb(num_faces)
    ax.cla()
    ax.axis('off')
    if int(check_slider.val) == 1:
        ax.add_collection3d(Poly3DCollection(poly3d, facecolors='b', edgecolors = 'black', alpha=1))
        ax.plot_surface(x, y, z, rstride=2, cstride=2, color='b', edgecolors='black', shade = True, antialiased=False)
    else:
        ax.plot_surface(x, y, z, rstride=1, cstride=1, color='b', edgecolors='black')
        ax.add_collection3d(Poly3DCollection(poly3d, facecolors='b', edgecolors='black', alpha=0.5))
    fig.canvas.draw_idle()

faces_slider.on_changed(update)

update(None)
plt.show()
