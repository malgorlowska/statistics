# statistics

My considerations on the probabilistic model "Balls and Bins".
In this model, m of balls are successively dropped into n numbered urns. Each ball is thrown independently with probability
equal to 1/n to one of the urns. We can equate throwing m balls into n urns in this way
with a random function from the set {1,. . . , m} into the set {1,. . . , n}.

The aim of this task is to experimentally determine the following values:
• Bn - moment of the first collision; Bn = k, if the k-th of the thrown balls is the first which
it ended up in an empty urn (birthday paradox),
• Un - number of empty urns after throwing n balls,
• Ln - maximum number of balls in the urn after throwing n balls (maximum load),
• Cn - the minimum number of throws after which in each urn there is at least one ball 
(the first moment after which there are no empty urns; coupon collector's problem),
• Dn - the minimum number of throws after which in each urn there are at least two balls (the
siblings of the coupon collector / coupon collector's brother),
• Dn −Cn - the number of throws from the moment Cn is needed so that there are something in every urn
at least two balls.

In folder:
- BallsBins there is implemention of the above simulations
- Statystyki there is implementation of methods to analyze collected data and present them on graphs.
