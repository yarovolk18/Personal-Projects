import numpy as np
import pandas as pd
import statistics as stat
import math as mt
import time


def Means(X):
    mu = np.zeros((1, X.shape[1]))
    for i in range(X.shape[1]):
        mu[0,i] = stat.mean(X[:,i])

    return mu


def SDs(X):
    sigma = np.ones((1, X.shape[1]))
    for i in range(X.shape[1]):
        sigma[0, i] = stat.stdev(X[:, i])

    return sigma


def Normalize(X):
    return np.true_divide((X - Means(X)), SDs(X))


def ComputeCost(X, y, theta):
    return np.dot(1/(2*y.shape[0]), np.dot((np.dot(X,theta) - y).T, (np.dot(X,theta) - y)))


def GradientDescent(X_g, y_g, theta_g, alpha_g, delta_g, lam_g):
    m = y_g.shape[0]
    counter = 0
    #mt.sqrt(np.dot((np.dot((np.dot(X_g,theta_g) - y_g).T, X_g)).T, np.dot((np.dot(X_g,theta_g) - y_g).T, X_g)))
    #(abs(np.dot((np.dot(X_g, theta_g) - y_g).T, X_g)[0, 0]) > delta_g
     #or abs(np.dot((np.dot(X_g, theta_g) - y_g).T, X_g)[0, 1]) > delta_g)
    while mt.sqrt((1/m) * np.dot(np.dot((np.dot(X_g, theta_g) - y_g).T, X_g),
                                 (np.dot((np.dot(X_g, theta_g) - y_g).T, X_g)).T)) > delta_g and counter <= 1/delta:
        theta_g_next = theta_g - (alpha_g/m) * (np.dot((np.dot(X_g, theta_g) - y_g).T, X_g).T + lam_g * theta_g)
        theta_g = theta_g_next
        counter += 1

    return theta_g, counter

def History(X, y, theta, iterations):
    Jhistory = np.zeros((iterations, 1))
    for i in range(iterations):
        Jhistory[i,0] = ComputeCost(X, y, theta)
    return Jhistory


# Main code
'''
data = np.loadtxt('ex1data2.txt', delimiter = ',')
X = data[:,0:2]
y = data[:,2].reshape((data.shape[0],1))
'''

df = pd.read_csv("D:\LR\Data_RE.csv")
print(df.head(5))
print("Data: ", df.shape)


# Filters
divider = 300
train = df.loc[lambda df_lambda: df['No'] <= 300, :]
test = df.loc[lambda df_lambda: df['No'] > divider, :]
print("Training Set: ", train.shape)
print("Test Set: ", test.shape)

# Training Set
# train["Age"], train["MRT"], train["Stores"], train["Lat"], train["Long"]
X_train = np.array((train["Age"], train["MRT"], train["Stores"], train["Lat"])).T

y = np.array((train["Price"])).T
y_train = y.reshape(y.shape[0],1)

# Normalize Features
X_train = Normalize(X_train)
print(X_train[0:10, :])

# Log Transformation
#X_train = np.log(X_train)

one_train = np.ones((X_train.shape[0],1))
X_train = np.concatenate((one_train, X_train), axis = 1)

# Test Set
# test["Age"], test["MRT"], test["Stores"], test["Lat"], test["Long"]
X_test = np.array((test["Age"], test["MRT"], test["Stores"], test["Lat"])).T

y_t = np.array((test["Price"])).T
y_test = y_t.reshape(y_t.shape[0],1)

# Normalize Features
X_test = Normalize(X_test)

# Log Transformation
#X_test = np.log(X_test)

one_test = np.ones((X_test.shape[0],1))
X_test = np.concatenate((one_test, X_test), axis = 1)



# Running Gradient Descent
alpha = 0.8 # 0.8 for training set
lam = 0
delta = 10**(-6)
np.random.seed(1)
theta = np.random.random((X_train.shape[1],1))

t0 = time.perf_counter()

theta_fit, steps = GradientDescent(X_train, y_train, theta, alpha, delta, lam)

t1 = time.perf_counter()
print()
print("Time: ", round(t1-t0,10), " seconds")
print()
s_sq = ComputeCost(X_train, y_train, theta_fit)[0,0]
predicted = np.dot(X_train, theta_fit)
y_estimate = sum(predicted)/predicted.shape[0]
print("Estimated Mean: ", y_estimate[0])
y_bar = Means(y_train)[0,0]
print("Sample Mean: ", y_bar)


print('Parameters computed from gradient descent:')
for i in range(theta_fit.shape[0]):
    print("b", i, " = ", round(theta_fit[i, 0], 4))

print("The algorithm took ", steps, " steps for threshold delta = ", delta, "and learning rate alpha = ", alpha)
print()
print("Training Set")
print("The value of the Cost function (Cost): ", round(s_sq, 4))
print("Standard Residual Error (SRE): ", round(mt.sqrt(2*X_train.shape[0]*s_sq/(X_train.shape[0]-X_train.shape[1])), 4))
print("Coefficient of variation (CV): ", round(100*mt.sqrt(2*s_sq)/y_estimate[0], 4), "%")

R = 1 - (np.dot((np.dot(X_train,theta_fit) - y_train).T, (np.dot(X_train,theta_fit) - y_train)))/\
    (np.dot((y_train - y_bar).T, (y_train - y_bar)))
print()
print("R^2 = ", round(R[0,0], 4))

# 95% CI (Training Set)
predicted = np.dot(X_train, theta_fit)
y_estimate = sum(predicted)/predicted.shape[0]
s = mt.sqrt(np.dot((y_train - predicted).T, (y_train - predicted))/(X_train.shape[0] - X_train.shape[1]))
low = y_estimate - 1.96*s/mt.sqrt(X_train.shape[0])
high = y_estimate + 1.96*s/mt.sqrt(X_train.shape[0])
print()
print("95 % CI on Training Set:")
print("[", round(low[0], 4), ",", round(high[0], 4),"]")

print()
print()
s_sq_test = ComputeCost(X_test, y_test, theta_fit)[0,0]
predicted_test = np.dot(X_test, theta_fit)
y_test_estimate = sum(predicted_test)/predicted_test.shape[0]
print("Estimated Mean: ", round(y_test_estimate[0], 4))
y_bar_test = Means(y_test)[0,0]
print("Sample Mean", round(y_bar_test, 4))
print()
print("Test Set")
print("The value of the Cost function (Cost): ", round(s_sq_test, 4))
print("Standard Residual Error (SRE): ", round(mt.sqrt(2*X_test.shape[0]*s_sq_test/(X_test.shape[0]-X_test.shape[1])), 4))
print("Coefficient of variation (CV): ", round(100*mt.sqrt(2*s_sq_test)/y_test_estimate[0], 2), "%")

# 95% CI (Test Set)
predicted_test = np.dot(X_test, theta_fit)
y_estimate_test = sum(predicted_test)/predicted_test.shape[0]
s_test = mt.sqrt(np.dot((y_test - predicted_test).T, (y_test - predicted_test))/(X_test.shape[0] - X_test.shape[1]))
low_test = y_estimate_test - 1.96*s_test/mt.sqrt(X_test.shape[0])
high_test = y_estimate_test + 1.96*s_test/mt.sqrt(X_test.shape[0])
print()
print("95 % CI on Test Set:")
print("[", round(low_test[0], 4), ",", round(high_test[0], 4),"]")



# Minimize Cost Test
y_bar_test = Means(y_test)[0,0]
alpha_set = [0.0001, 0.0003, 0.001, 0.003, 0.01, 0.03, 0.1, 0.3, 0.6, 0.8, 0.9]
# alpha_set = [0.1, 0.3, 1, 2, 3, 4, 5, 6, 7]
test_error = []
steps_set = []
theta_set = []
for i in range(len(alpha_set)):
    rate = alpha_set[i]
    theta_fit, steps = GradientDescent(X_train, y_train, theta, rate, delta, lam)
    test_error.append(ComputeCost(X_test, y_test, theta_fit)[0, 0])
    theta_set.append(theta_fit)
    steps_set.append(steps)
for j in range(len(test_error)):
    if test_error[j] == min(test_error):
        result = j
print()
print("Choosing best value for learning rate on the Test Set:")
print("Best alpha: ", alpha_set[result])
print("Best Cost: ", round(test_error[result], 4), " with number of steps needed: ", steps_set[result])
print("Standard Residual Error (SRE): ", round(mt.sqrt(2*X_test.shape[0]*test_error[result]/
                                                       (X_test.shape[0]-X_test.shape[1])), 4))
print("Coefficient of variation (CV): ", round(100*mt.sqrt(2*test_error[result])/y_bar_test, 2), "%")
print("Parameters:")
for i in range(theta_set[result].shape[0]):
    print("b", i, " = ", round(theta_set[result][i, 0], 4))


print("Test errors:")
print(test_error)
#print("Parameters: ")
#print(theta_set)
print("Steps: ")
print(steps_set)

