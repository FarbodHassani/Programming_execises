function [all_theta] = oneVsAll(X, y, num_labels, lambda)
%ONEVSALL trains multiple logistic regression classifiers and returns all
%the classifiers in a matrix all_theta, where the i-th row of all_theta 
%corresponds to the classifier for label i
%   [all_theta] = ONEVSALL(X, y, num_labels, lambda) trains num_labels
%   logistic regression classifiers and returns each of these classifiers
%   in a matrix all_theta, where the i-th row of all_theta corresponds 
%   to the classifier for label i

% Some useful variables
m = size(X, 1); % examples 
n = size(X, 2); % dimension of each example (no of features)

% You need to return the following variables correctly 
all_theta = zeros(num_labels, n + 1);

% Add ones to the X data matrix
X = [ones(m, 1) X];

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the following code to train num_labels
%               logistic regression classifiers with regularization
%               parameter lambda. 
%
% Hint: theta(:) will return a column vector.
%
% Hint: You can use y == c to obtain a vector of 1's and 0's that tell you
%       whether the ground truth is true/false for this class.
%
% Note: For this assignment, we recommend using fmincg to optimize the cost
%       function. It is okay to use a for-loop (for c = 1:num_labels) to
%       loop over the different classes.
%
%       fmincg works similarly to fminunc, but is more efficient when we
%       are dealing with large number of parameters.


%Set Initial theta
%initial_theta = zeros(n + 1, 1);

% Set options for fminunc as global 
options = optimset('GradObj', 'on', 'MaxIter', 50);
 
% should loop over the k classifiers (in example this is 10) and populate
% the theta matrix row by row. Each theta row corresponds to a classifiers
% and each column to the weights of the individual features 

% Run fmincg to obtain the optimal theta
% This function will return theta and the cost 

for i = 1:num_labels
     ithet = zeros(n + 1, 1); % make column vector of weights for jth classifier 
     %fin_thet is the stored optimal weights in a colum vector form. 
    [fin_thet] =  fmincg (@(t)(lrCostFunction(t, X, (y == i), lambda)), ithet, options);
    % assign fitted theta to the matrix elements of theta. Note fin_thet is
    % a n+1 x 1 vector and should be the ith row of theta 
    all_theta(i,:) = fin_thet' 
end 


% =========================================================================


end
