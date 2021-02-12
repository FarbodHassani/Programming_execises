function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

X = [ones(m, 1) X];

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%


% Layer 2 outputs (a^2_i, i from 1 to 26) 
a2 = sigmoid(Theta1*X')'; % this is a mx25 matrix 

% add bias unit column 
a2 = [ones(m, 1) a2];  % becomes a m x 26 matrix 

% Layer 3 part 1 
a3 = sigmoid(a2 * Theta2'); % gives a m x 10 matrix 

% finally, do the same as in predictOneVsAll.m to get the prediction
[myp,p] = max(a3,[],2);

%reset the 0 values to 10
p(p == 0) = 10;
% =========================================================================


end
