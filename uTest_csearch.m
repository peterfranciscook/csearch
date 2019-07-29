
% preallocate appropriate arrays
t0 = now();
d = max(1,randi(4));
tf = now() + d;
n_test = 7;
n_repetition = 1000;
num = logspace(2, 2 + n_test - 1, n_test);
x_min_pct = randi([2,50], n_repetition, 1)/100;
x_max_pct = randi([51,99], n_repetition, 1)/100;
x_min_arr = t0 + d * x_min_pct;
x_max_arr = t0 + d * x_max_pct;
%idx_out_argmin = zeros(1,2,'int64');
idx_out_argmin = 0;
idx_out_argmax = 0;
dt = 0;
dt_matlab = 0;

%% double precision
fprintf('double precision\n');
k = 1;
% num = 100
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = linspace(t0, tf, num(k));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
    %dt = dt + toc;
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
    %dt_matlab = dt_matlab + toc;
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);
k = k + 1;

% num = 1000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = linspace(t0, tf, num(k));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 10000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = linspace(t0, tf, num(k));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 100000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = linspace(t0, tf, num(k));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 1000000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = linspace(t0, tf, num(k));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 10000000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = linspace(t0, tf, num(k));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);
fprintf('%c',repmat(37,1,80));
fprintf('\n');

%% single precision
fprintf('single precision\n');
k = 1;
% num = 100
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = single(linspace(t0, tf, num(k)));
x_min_arr = single(x_min_arr);
x_max_arr = single(x_max_arr);

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);
k = k + 1;

% num = 1000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = single(linspace(t0, tf, num(k)));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 10000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = single(linspace(t0, tf, num(k)));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 100000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = single(linspace(t0, tf, num(k)));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 1000000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = single(linspace(t0, tf, num(k)));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);

k = k + 1;

% num = 10000000
fprintf('num = %i, %0.0f repetitions\n', num(k), n_repetition);
x = single(linspace(t0, tf, num(k)));

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin_matlab = csearch(x, 'gt', x_min);
    idx_out_argmax_matlab = csearch(x, 'lt', x_max);
end
dt = toc;

tic
for k_rep = 1:n_repetition
    x_min = x_min_arr(k_rep);
    x_max = x_max_arr(k_rep);
    idx_out_argmin = find(x > x_min, 1, 'first');
    idx_out_argmax = find(x < x_max, 1, 'last');
end
dt_matlab = toc;

fprintf('csearch: %0.8f s, MATLAB: %0.8f s\n', dt, dt_matlab);
fprintf('%c',repmat(37,1,80));
fprintf('\n');
