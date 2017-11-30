ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll d;
    if(b == 0) {x = 1; y = 0; return a;}
    d = extended_euclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll china(ll b[], ll w[], ll len) { 
    ll i, d, x, y, m, n, ret;
    ret = 0; n = 1; 
    for(i=0; i < len ;i++) n *= w[i];
    for(i=0; i < len ;i++) { 
        m = n / w[i];
        d = extended_euclid(w[i], m, x, y);
        ret = (ret + mul(y,mul(m,b[i],n),n)) % n;
        //ret = (ret + y*m*b[i]) % n;
    }
    return (n + ret%n) % n;
}
