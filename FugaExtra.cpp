if(blc[x-1][y] == 0) {
	debug(" => Case 1\n");

	blc[x-1][y] = 1;
	backtrack(newX, newY, inc+1);

	// if(newY < m) backtrack(newX, newY, inc+1);
	// if(newX == n-1 && newY == m-1) {
	// 	bfs(bx, by);
	// 	ans = max(ans, dst[gx][gy]);
	// }
}
if(blc[x+1][y] == 0) {
	debug(" => Case 2\n");

	blc[x+1][y] = 1;
	backtrack(newX, newY, inc+1);
	// if(newY < m) backtrack(newX, newY, inc+1);
	// if(newX == n-1 && newY == m-1) {
	// 	bfs(bx, by);
	// 	ans = max(ans, dst[gx][gy]);
	// }
}
if(blc[x][y-1] == 0) {
	debug(" => Case 3\n");

	blc[x][y-1] = 1;
	backtrack(newX, newY, inc+1);
	// if(newY < m) backtrack(newX, newY, inc+1);
	// if(newX == n-1 && newY == m-1) {
	// 	bfs(bx, by);
	// 	ans = max(ans, dst[gx][gy]);
	// }
}
if(blc[x][y+1] == 0) {
	debug(" => Case 4\n");

	blc[x][y+1] = 1;
	backtrack(newX, newY, inc+1);
	// if(newY < m) backtrack(newX, newY, inc+1);
	// if(newX == n-1 && newY == m-1) {
	// 	bfs(bx, by);
	// 	ans = max(ans, dst[gx][gy]);
	// }
}
