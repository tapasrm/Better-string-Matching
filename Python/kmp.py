def kmp_matcher(t,p):
    n=len(t)
    m=len(p)
    pi=[0]*n;
    pi = compute_prefix_function(p)
    q=-1
    for i in range(n):
        while(q>0 and p[q]!=t[i]):
            q=pi[q]
        if(p[q]==t[i]):
            q=q+1
        if(q==m):
            print("pattern occurs with shift "+str(i-m))
            q=pi[q]


def compute_prefix_function(p):
    m=len(p)
    pi =range(m)
    pi[1]=0
    k=0
    for q in range(2,m):
        while(k>0 and p[k]!=p[q]):
            k=pi[k]
        if(p[k]==p[q]):
            k=k+1
        pi[q]=k
    return pi

t = 'brownfoxlazydog'
p = 'lazy'
kmp_matcher(t,p)
