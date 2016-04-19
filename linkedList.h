typedef struct node {
    char *val;
    struct node * next;
} node_t;

node_t initList();
void addNode(node_t node, char *val);

node_t initList()
{
	node_t *head = NULL;
	head = malloc(sizeof(node_t));
	head->val = NULL;
	head->next = NULL;
	return *head;
}
void addNode(node_t n, char *val)
{
	n.next = malloc(sizeof(node_t));
	n.next->val = val;
	n.next->next = NULL;
}