function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%


%Compute the cost 

%Add column of 1s to X 

% X = [ones(m, 1) X];

% % 2nd layer activation units a2 
% 
% % this is a 5000 x 25 matrix that includes all a2 for all 5000 examples 
% 
% A2 = sigmoid(X*Theta1') ;
% 
% %Add column of 1s to A2
% A2 = [ones(m, 1) A2];
% 
% % 3rd layer (h) 
% 
% % this is a 5000 x 10 matrix that includes the predictions for each
% % classifier for the 5000 examples 
% 
% A3 = sigmoid(A2*Theta2'); 
% 
% 
% % we need to sum over all classifiers
% % reformat y to a 5000 x 10 matrix 
% 
% yt = zeros(m,num_labels); 
% 
% tic 
% for j = 1:m
%    yt(j,y(j))=1;
%    % Option 1: can loop the sum
%    % J = J + (-yt(j,:)*log(A3(j,:))' - (ones(size(yt(j,:))) - yt(j,:))*log(ones(size(A3(j,:))) - A3(j,:))')/m;
% end
% 
% %Option 2: can just calculate the trace (this is much faster ~ order of
% %mag) 
% J = 1/m * trace(-yt' * log(A3) - (ones(size(yt)) - yt)'* log(ones(size(A3)) - A3));
% 
% toc

% Add regularisation term for Theta1 and Theta2

%reg1 = lambda/2/m*(sum(sum(Theta1.^2))-sum(Theta1(:,1).^2)) ;

%reg2 = lambda/2/m*(sum(sum(Theta2.^2)) -sum(Theta2(:,1).^2));

%J = J + reg1 + reg2;

% -------------------------------------------------------------

%PART 2) Time for backprop :o 

%Given our initial theta, we run forward prop as above so I will just copy
%and paste and comment out the above algoirthm 
X = [ones(m, 1) X];
yt = zeros(m,num_labels); 
Delta1 = 0;
Delta2 = 0; 
for j = 1:m
    % create y vector for jth example 
    yt(j,y(j))=1; % this is a 5000 x 10 matrix 
    
    % take jth input feature x_j 
    
    xj = X(j,:); % 1 x 401 vector for the example 
    
    % 2nd layer activation units a2 

    a2j = sigmoid(xj*Theta1'); % this is a 1 x 25 vector for the example

    %Add column of 1s to A2
    a2j = [1 a2j]; %1 x 26 vector 
    
    % 3rd layer (h) 
    
    a3j = sigmoid(a2j*Theta2'); % this is a 1 x 10 vector for the example
        
    %Compute the error delta^L
    
    delta3 = a3j - yt(j,:); % this is a 1 x 10 vector for the example
    
    %Compute all other deltas 
    delta2 = delta3*Theta2.*[1 sigmoidGradient(xj*Theta1')]; % this is a 1 x 26 vector
    
    %Compute big Delta 
    Delta1 = Delta1 + xj'*delta2(2:end); % this is a 401 x 25 matrix 
    Delta2 = Delta2 + a2j'*delta3; % this is a 26 x 10 matrix 
    
    J = J + (-yt(j,:)*log(a3j)' - (ones(size(yt(j,:))) - yt(j,:))*log(ones(size(a3j)) - a3j)')/m;
end


reg1 = lambda/2/m*(sum(sum(Theta1.^2))-sum(Theta1(:,1).^2)) ;

reg2 = lambda/2/m*(sum(sum(Theta2.^2)) -sum(Theta2(:,1).^2));

J = J + reg1 + reg2;

Theta1_grad = Delta1'/m + lambda/m * Theta1;
Theta2_grad = Delta2'/m + lambda/m * Theta2;
%deduct first column of Theta1,2
Theta1_grad(:,1) = Theta1_grad(:,1) - lambda/m * Theta1(:,1); 
Theta2_grad(:,1) = Theta2_grad(:,1) - lambda/m * Theta2(:,1); 

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
