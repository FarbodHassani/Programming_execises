function [C, sigma] = dataset3Params(X, y, Xval, yval)
%DATASET3PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = DATASET3PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%
% You need to return the following variables correctly.
C = 0;
sigma = 0;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%

% So let's break this down : 
% First, for a given C and sigma, we want to train on the TS for a model 
% Second, we use this model to compute predictions on the CV set 
% Third, we calculate the error from the predictions 
% Fourth we choose the model with the lowest error. 

% Step 1 : 
% nested Loop over values of C and sigma in multiples of 3  --- 8 values
% each 

% You need to return the following variables correctly.
Cinit = 0.01;
sigmainit = 0.01;


maxi = 8;
maxj = 8;

values=[0.01 0.03 0.1 0.3 1 3  10 30];

% vector of 1 row and k (= number of models) columns 
modelpred = zeros(maxi,maxj); 

for i = 1:maxi
    myC = values(i);
    
        for j = 1:maxj
            
            mysig = values(j);
            
            %Train model 
            model = svmTrain(X, y, myC, @(x1, x2)gaussianKernel(x1, x2, mysig)); %step 1
            
            prediction = svmPredict(model, Xval);  %step 2 
            
            modelpred(i,j) = mean(double(prediction ~= yval)); %step 3 
            
        end 
end


%step 4 --- find lowest error 

% find minimum of each column 
[m,ci] = min(modelpred);


% find index of min sigma (row) 
[mm, sigi] = min(m) ;

Ci = ci(sigi);

C = values(Ci);
sigma = values(sigi);

% =========================================================================

end
