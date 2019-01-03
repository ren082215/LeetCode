class Solution {
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int overlap_width = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0; 
            int overlap_height = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
            return ((C - A) * (D - B) - overlap_width * overlap_height) + (G - E) * (H - F); // order avoids overflow
        }
    };
