% Define the data
voltage = [0.003, 0.032, 0.044, 0.047, 0.061, 0.068, 0.082, 0.103, 0.112, 0.13, 0.143, 0.155, 0.173, 0.203, 0.226, 0.254, 0.306, 0.333, 0.382, 0.408, 0.5, 0.61, 0.703];
current = [1.52, 1.546, 1.553, 1.56, 1.572, 1.578, 1.559, 1.609, 1.617, 1.633, 1.645, 1.655, 1.672, 1.699, 1.719, 1.744, 1.791, 1.816, 1.859, 1.882, 1.965, 2.064, 2.146];

% Plot the data
plot(voltage, current, 'o');

% Set the axis labels
xlabel('Voltage');
ylabel('Current');


% Define the data
voltage = [0.003, 0.032, 0.044, 0.047, 0.061, 0.068, 0.082, 0.103, 0.112, 0.13, 0.143, 0.155, 0.173, 0.203, 0.226, 0.254, 0.306, 0.333, 0.382, 0.408, 0.5, 0.61, 0.703];
current = [1.52, 1.546, 1.553, 1.56, 1.572, 1.578, 1.559, 1.609, 1.617, 1.633, 1.645, 1.655, 1.672, 1.699, 1.719, 1.744, 1.791, 1.816, 1.859, 1.882, 1.965, 2.064, 2.146];

% Perform polynomial regression
p = polyfit(voltage, current, 4);

% Evaluate the function over a range of voltages
voltage_range = linspace(min(voltage), max(voltage), 100);
current_approx = polyval(p, voltage_range);

% Plot the data and the approximate function
plot(voltage, current, 'o', voltage_range, current_approx);
xlabel('Voltage');
ylabel('Current');
legend('Data', 'Approximation');
