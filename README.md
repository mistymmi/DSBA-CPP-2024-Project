# DSBA-CPP-2024-Project
# Console Application for Clustering Data
## by Yakupova Maryam, Zhidkova Ekaterina, group 233-2
## Description:
The aim of this project is to develop a versatile console application for clustering
analysis. The application should be designed to be usable both as a standalone
program and as a library for integration into other projects. Clustering algorithms
will primarily be implemented using the k-means algorithm due to its efficiency
and ease of use.
## Dataset:
The dataset provided for this project from kaggle is 2D clustering data, containing
two-dimensional clustering data and right clusterization. You will need to delete
column with right classes and make clussterization, after that you can compare
with right clussterization. Dataset includes the following fields:
1) x : Float
2) y : Float
3) color : integer
This dataset is ideal for testing and implementing clustering algorithms, as it
allows for easy visualization and interpretation of results.
## Features to Implement:
### 1. Clustering Algorithms:
• Input: Preprocessed matrix of two-dimensional data points.
• Number of clusters: Allow the user to specify the desired number of
clusters.
• Output: Marked clusters for input data.
### 2. Supplementary Functionality:
• Reading and Writing: Implement functions to read data from files and
write clustered data to files for easy storage and retrieval.
• Documentation: Provide comprehensive documentation including usage
examples to guide users in utilizing the application and library
functionalities effectively.
## Additional Features:
### 1. Interpretation Algorithm
• Develop an algorithm to interpret and visualize the clustered data
effectively. For example in scatter plot.
### 2. Algorithm Flexibility:
• Besides k-means, provide options for implementing other clustering
algorithms such as hierarchical clustering or DBSCAN for comparative
analysis.
### 3. Visualization Tools:
• Integrate visualization tools to allow users to visualize the clustering
results directly within the console application.
### 4. Normalization function:
• Include function to normalize data after reading to impprove accuracy of 
algorithms especially with large datasets.
### 5. Parameter Tuning:
• Include functionality for automatic or manual tuning of clustering
parameters such as the number of clusters to optimize clustering
performance.
### 6. Exportable Results:
• Allow users to export clustered data and visualizations in various formats
(e.g., CSV, image files) for further analysis or presentation purposes.

By incorporating these additional features, the console application will not only
provide basic clustering functionalities but also offer flexibility, performance, and
user-friendliness, making it a valuable tool for data analysis tasks.
