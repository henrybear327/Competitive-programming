# Notes

### 11340

When trying to get the char's ascii code, remember to add 128 to it to avoid
"overflow" problem!!!

```
char c[10];
int cost;
scanf("%s %d", c, &cost);

pay[(int)c[0] + 128] = cost; //crucial!!
```

### 12356

Brute force scanning method will get TLE. Need to imitate linked list concept, recording
prev and next node for fast query.
