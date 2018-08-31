import sys
import scipy.io 
from scipy import stats
import numpy as np
from numpy import *
import matplotlib.pyplot as plt

sys.path.append("/Users/renminghe/Desktop/Algorithm-Exercises/knn_model")

def plotdata(xtrain, ytrain):
	"""Plot original data.

	Args:
	    xtrain: train data
		ytrain: train label
	Returns:
		None
	"""
	plt.scatter(xtrain[:,0],xtrain[:,1],ytrain==1, c= 'red');
	plt.scatter(xtrain[:,0],xtrain[:,1],ytrain==2, c= 'green');
	plt.scatter(xtrain[:,0],xtrain[:,1],ytrain==3, c= 'blue');
	plt.figure(1)
	plt.title("Training Dataset")
	plt.xlabel('X1')
	plt.ylabel('X2')
	plt.show()

def plotprob(class1_probs,class2_probs,class3_probs):
	"""Plot classification probability

	Args:
	    class1_probs: class one probability
		class2_probs: class two probability
		class3_probs: class three probability
	Returns:
		None
	"""
	plt.figure(1)
	plt.imshow(class1_probs,extent=[-3.5,6,-3,6]);
	plt.colorbar()
	plt.title("probability of being class 1")
	plt.xlabel('X1')
	plt.ylabel('X2')
	
	plt.figure(2)
	plt.imshow(class2_probs,extent=[-3.5,6,-3,6]);
	plt.colorbar()
	plt.title("probability of being class 2")
	plt.xlabel('X1')
	plt.ylabel('X2')

	plt.figure(3)
	plt.imshow(class3_probs,extent=[-3.5,6,-3,6]);
	plt.colorbar()
	plt.title("probability of being class 3")
	plt.xlabel('X1')
	plt.ylabel('X2')
	plt.show()

def plotpredict(xtrain, ytrain,knn_classifier):
	"""Plot original data and classification result

	Args:
	    xtrain: train data
		ytrain: train label
		knn_classifier: knn_classifier
	Returns:
		None
	"""
	plt.figure(1)
	plt.scatter(xtrain[:,0],xtrain[:,1],ytrain==1, c= 'red');
	plt.scatter(xtrain[:,0],xtrain[:,1],ytrain==2, c= 'green');
	plt.scatter(xtrain[:,0],xtrain[:,1],ytrain==3, c= 'blue');
	plt.title("Training Dataset")
	plt.xlabel('X1')
	plt.ylabel('X2')

	plt.figure(2)
	plt.scatter(knn_classifier[:,0],knn_classifier[:,1],knn_classifier[:,2]==1, c= 'red');
	plt.scatter(knn_classifier[:,0],knn_classifier[:,1],knn_classifier[:,2]==2, c= 'green');
	plt.scatter(knn_classifier[:,0],knn_classifier[:,1],knn_classifier[:,2]==3, c= 'blue');
	plt.title("Prediction")
	plt.xlabel('X1')
	plt.ylabel('X2')	
	plt.show()


def main():
	
	# Load data
	data = scipy.io.loadmat('data_knnSimulation.mat')
	xtrain = data['Xtrain']
	ytrain = data['ytrain']
	# numofdata = 200
	numofdata = len(xtrain[:,0])
	

	# Initiation
	x_range = np.arange(-3.5,6 +0.1,0.1);
	y_range = np.arange(-3,6 + 0.1,0.1);
	# Number of neighbor
	knn = 10
	points = np.zeros((numofdata,2))
	points[:,0] = xtrain[:,0]
	points[:,1] = xtrain[:,1] 
	class1_probs= np.zeros((len(y_range),len(x_range)));
	class2_probs= np.zeros((len(y_range),len(x_range)));
	class3_probs= np.zeros((len(y_range),len(x_range)));
	knn_classifier= np.zeros((len(x_range)*len(y_range),3));

	for i in range(0, len(x_range)):
		for j in range(0, len(y_range)):
			point = np.array([x_range[i],y_range[j]])
			points= np.insert(points, numofdata, point, 0)
			points = mat(points)

			# Calculate the Euclidean distance
			ED = np.diag(points * np.transpose(points)) - 2* (points * np.transpose(points)) + np.transpose(mat(np.diag(points * np.transpose(points))))
			distances = np.zeros((len(points),2))
			distances[:,0] = ED[numofdata,:]
			# Add point index
			for k in range(1,numofdata):
				distances[k,1] = k
			# Delete the last extra row
			distances = np.delete(distances, numofdata, 0)
			# Sort Euclidean distances
			distances = distances[distances[:,0].argsort()]
			points_index = distances[:,1]
			points_index = list(map(int, points_index))
			nearsts_index = points_index[0:knn];
			nearsts_class = ytrain[nearsts_index];

			# Get probabilities for each class, count 1 when there is a class match
			class1_probs[j,i]=sum(nearsts_class==1)/knn;
			class2_probs[j,i]=sum(nearsts_class==2)/knn;
			class3_probs[j,i]=sum(nearsts_class==3)/knn;

			# Perform classification
			knn_classifier[j+len(y_range)*i,[0,1]]=point;
			m = stats.mode(nearsts_class)
			knn_classifier[j+len(y_range)*(i),2]=m[0][0]
			points = np.delete(points, numofdata, 0)

	# Flip data to plot
	class1_probs = flip(class1_probs,0)
	class2_probs = flip(class2_probs,0)
	class3_probs = flip(class3_probs,0)
	# plotdata(xtrain,ytrain)
	plotpredict(xtrain,ytrain,knn_classifier)
	plotprob(class1_probs,class2_probs,class3_probs)

if __name__ == "__main__":
    main()
