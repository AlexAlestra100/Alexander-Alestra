edge(v5,v4,3).
edge(v0,v1,3).
edge(v1,v4,2).
edge(v0,v3,2).
edge(v3,v4,1).
edge(v0,v2,1).
edge(v2,v0,1).

boundary(X,Y,N,_H) :-
    edge(X,Y,N).

boundary(X,Y,N,H) :-
    H > 0,
    Hop is H - 1,
    edge(X,Z,M),
    edge(Z,Y,K),
    %K =< M,
    N is M + K,
    boundary(Z,Y,K,Hop).

findBoundary(X,Y,N,H) :- boundary(X,Y,N,H).

findBoundary(X,Y,N,H) :-
    %\+ boundary(X,Y,N,H),
    P is H + 1,
    findBoundary(X,Y,N,P).

pathBound(X,Y,N,L) :-
	edge(X,Y,N),
    N < L.
    
pathBound(X,Y,N,L) :-
	edge(X,Z,M),
    edge(Z,Y,P),
	K is L - M,
    K > 0,
    N is P + M,
    pathBound(Z,Y,P,K).
      
shortestPath(X,Y,N) :- 
	findBoundary(X,Y,N,0),
    \+ pathBound(X,Y,_,N).