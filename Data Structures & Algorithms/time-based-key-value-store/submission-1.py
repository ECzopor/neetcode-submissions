class TimeMap:

    def __init__(self):
        self.dic = {}
    
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.dic:
            self.dic[key] = [(timestamp, value)]
        else:
            self.dic[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.dic:
            return ""
        ls = self.dic[key];
        if ls[0][0] > timestamp:
            return ""

        #later delete
        print(ls)

        s = 0
        e = len(ls) -1
        mid = (s + e)//2
        while s < e:
            if ls[mid][0] == timestamp:
                return ls[mid][1]
            if ls[mid][0] > timestamp:
                e = mid
            elif ls[mid][0] < timestamp:
                s = mid
            mid = (e+s)//2

            if e - s == 1:
                if ls[e][0] <= timestamp:
                    return ls[e][1]
                return ls[s][1]

        return ls[mid][1]


