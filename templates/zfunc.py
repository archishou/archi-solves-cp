def zfunc(s):
    out = [0 for _ in range(len(s))]
    left, right = 0, 0
    for idx in range(1, len(s)):
        if idx < right:
            out[idx] = min(out[idx - left], right - idx)
        while idx + out[idx] < len(s) and s[out[idx]] == s[idx + out[idx]]:
            out[idx] += 1
        if idx + out[idx] > right:
            left = idx
            right = out[idx] + idx
    return out
