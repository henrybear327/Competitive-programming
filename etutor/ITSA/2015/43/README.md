# PTC-2015-11解題概要：(by Bangye)

## PTC-1

一個圖上的邊有距離與風險兩個值，要找出兩點之間風險最小的路徑中最短路徑。風險是路徑所經過的邊的風險最大值。先把風險由小而大的找出可以讓兩點相通的最小風險值，然後再使用dijkstra找最短就可以了。第一步使用priority queue+find&union，是典型的題目。如果使用binary search找風險值應該也可以過。

(這裡是一個錯誤，無向圖才能用這個方法，有向圖就使用binary search找連通的最小風險值，太久之前寫的，昨天其實偷懶沒看題目，立刻出包)

## PTC-2

平面上一直疊矩形色紙，要問最後各個顏色的面積。1200個矩形時限五秒，其實不需要特殊的資料結構，但是面積範圍大不能用模擬方式一直複寫，必須maintain目前所有(可能被切碎的)矩形，重點是，每放一個下去，check那些會被他覆蓋到，被蓋到的以切開來處理，最多一塊切四塊，最後總共可能有O(n^2)個方塊。這題有點苦工。

## PTC3

hypercube上面找s經過p,q到達t的最短路徑。hypercube的結構與binary表示法密切相關，找最短路徑用xor就可以，這一題的關鍵在於必須找出lexicographically smallest的路徑，這必須動一動腦筋。先確定s-p-q-t或s-q-p-t比較短，然後分三段輸出。兩點間要找lexicographic order最小的最短路徑，XOR找difference後，從LSB(bit 0)開始變就對了。

(這裡也是一個錯誤，不能找理由了，兩周前寫過的就忘了，要掃兩次，下面這個作法才對:
First find the different bits by XOR.
Change the different bits which are 1 in the source for MSB to LSB.
Change the different bits which are 0 in the source for LSB to MSB.
)

## PTC4

找樹上的最大毛毛蟲。一個tree如果拿掉所有的葉子會變成PATH則稱為毛毛蟲，這是圖論上的名詞。tree的問題十之八九可以用bottom-up Dp解，這一題也不例外，解法很像求diameter只是會比較複雜一些，在考慮一點時，最大毛毛蟲要嘛掛在他兩個子樹或者往上穿過，每個點要記兩個最大子樹毛蟲，同時要小心只有一個child的情形。

## PTC5

要考慮的東西很多，小數做法或許與轉分數作差不多麻煩。但小數作要考慮的很多：

1. 先對齊循環
2. 兩循環長度的最小公倍數
3.大數加法
4.考慮循環節縮短(repeat)
5. 檢查特殊狀況(9循環)
6.結果沒小數時不能輸出小數點。
(在4之前需要考慮把循環節往左移了。如 0.3(23) 可以移成 0.(32)，這一題我沒做過，因此考慮不周，謝謝讀者來信指正)

# ITSA-2015-11(43th) 解題概要：(by Bangye)

## ITSA-1

時差轉換，這題如果有困難應該會發生在輸入的讀取，因為有字串，不過假設測資無誤的情形下，地區代碼很容易分別，地區並不多，寫幾個case就可以解。

## ITSA-2

邊緣偵測，讀入一個二維矩陣，找出每個旁邊有0的1，雙迴圈搭二維矩陣，注意邊界就不會有問題了

## ITSA-3

老鼠走迷宮是標準back track或DFS屬於DS的題目。

## ITSA-4

是graph上算betweenness的一個步驟，目的使找兩點間的最短路徑數目以及其中有幾條穿過某V點，使用起點當root的BFS變形，就可以解了，與傳統BFS不同稍微麻煩的是必須知道每個點的parent有哪些，因為點數不多，使用二維陣列存adjacent matrix，在出queue要往下長的時候，檢查有邊相連且距離值少一的就是parent。要計算通過V的最短路徑數，可以把V先mark成visited，在算出的就是不含V的路徑數，一個函式呼叫兩次就OK了。

## ITSA-5

英文題，在metric graph(滿足三角不等式的完全圖)上求next to shortest path，要看出最佳解最多兩個中間點，然後窮舉就好了。
