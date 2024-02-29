for (int i = 0; i < n; i++) {
        if (!visited_dfs[i]) {
            dfs_stack(adjaceny_matrix,i,visited_dfs,n,pushorder,poporder);
        }
    }