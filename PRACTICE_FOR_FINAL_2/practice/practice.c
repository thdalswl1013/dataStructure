
int hasing(char input[])
{
	int num = 0;
	while (*input)
	{
		num += *input;
		input++;
	}
	return num;
}

int HashAdd(element temp, element* ht)
{
	int i, value;
	value = i = stringToint(temp.item) % 11;

	while (ht[i].empty == 1) // 해시 테이블이 채워져있으면
	{
		i = (i + 1) % 11; // 옆 칸으로 이동 후 버킷 수 만큼 나눠
	}

	temp.key = hasing(temp.item);
	temp.empty = 1; // temp 값이 채워져있다고 바꿔준 후
	ht[i] = temp; // ht[i]에 집어넣어

	return 1;
}

그래프 insert



void insert(int x, int y)
{
	nodePointer temp;
	temp = (nodePointer)malloc(sizeof(*temp));
	temp->data = y;

	if (graph[x])
	{
		temp->link = graph[x];
		graph[x] = temp;
	}

	else
	{
		temp->link = NULL;
		graph[x] = temp;
	}
}


------------------------------------------------------

printf("adjacency list\n");

for (int i = 0; i < vertex; i++)
{
	printf("\nadjList[%d]: ", i);

	for (nodePointer ptr = graph[i]; ptr; ptr = ptr->link)
		printf("%3d", ptr->data);
}
-------------------------------------------------------------- -



void dfs(int v)
{
	found[v] = 1;
	printf("%3d", v);

	for (nodePointer ptr = graph[v]; ptr; ptr = ptr->link)
	{
		if (!found[ptr->data])
			dfs(ptr->data);
	}
}
-------------------------------------------------------------- -
int cnt = 1;

for (int i = 0; i < vertex; i++)
{
	if (!found[i])
	{
		printf("\nconnected %d: ", cnt++);
		dfs(i);
	}
}

