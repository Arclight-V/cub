#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void   ft_lstclear1(t_list **lst, void (*del)(void *)) 
{ 
       t_list tmp; 
 
       tmp = *lst; 
       if (*lst && del) 
       { 
               ft_lstclear1(tmp->next, del); 
               ft_lstdelone(tmp, del); 
       } 
       return ; 
}
void			print_list(t_list *lst)
{
	printf("List:\n");
	if (lst)
	{
		while (lst->next)
		{
			printf("%s->", (char*)(lst->content));
			lst = lst->next;
		}
		printf("%s->NULL\n", (char*)(lst->content));
	}
	else
		printf("NULL\n");
}

void			delete_content(void *content)
{
	printf("I'm deleting the content %s of list\n", (char*)content);
}

void 			print_content(void *content)
{
	printf("I'm printing the content %s of list\n", (char*)content);
}

void 			*changed_content(void *content)
{
	return (void*)("BA");
}

void *		lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

int				__delNum = 0;
void			lstdel_f(void *lst) {
	(void)lst;
	__delNum++;
}

static int		g_delone_called = 0;
void			lstdelone_f(void *d) {
	printf("Called del function for content %s\n", (char*)d);
	free(d);
	g_delone_called = 1;
}

void		test_lstclear1()
{
	printf("Testing lstclear:\n");
	t_list	*l = ft_lstnew(ft_strdup("nyancat"));

	l->next = ft_lstnew(ft_strdup("#TEST#"));
	print_list(l);
	ft_lstclear1(&l, lstdelone_f);
	print_list(l);
	printf("\n");
}

void	test_lstadd_front()
{
	printf("Testing lstadd_front:\n");
	t_list *lst;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew((void*)("2")));
	ft_lstadd_front(&lst, ft_lstnew((void*)("1")));
	ft_lstadd_front(&lst, ft_lstnew((void*)("0")));
	print_list(lst);
	printf("Size of list is %d, content of last element is %s\n", ft_lstsize(lst), (char*)(ft_lstlast(lst))->content);
	printf("\n");
}

void	test_lstadd_back()
{
	printf("Testing lstadd_back:\n");
	t_list *lst;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void*)("2")));
	ft_lstadd_back(&lst, ft_lstnew((void*)("1")));
	ft_lstadd_back(&lst, ft_lstnew((void*)("0")));
	print_list(lst);
	printf("\n");
}

void	test_lstiter()
{
	printf("Testing lstiter:\n");
	t_list *lst;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void*)("2")));
	ft_lstadd_back(&lst, ft_lstnew((void*)("1")));
	ft_lstadd_back(&lst, ft_lstnew((void*)("0")));
	print_list(lst);
	ft_lstiter(lst, &print_content);
	printf("\n");
}
void	test_lstmap()
{
	printf("Testing lstmap:\n");
	t_list *lst;
	t_list *lst_new;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void*)("2")));
	ft_lstadd_back(&lst, ft_lstnew((void*)("1")));
	ft_lstadd_back(&lst, ft_lstnew((void*)("0")));
	print_list(lst);
	lst_new = ft_lstmap(lst, &changed_content, &delete_content);
	print_list(lst_new);
	printf("\n");
}

int main()
{
	// test_lstadd_front();
	// test_lstadd_back();
	// test_lstiter();
	// test_lstmap();
	test_lstclear1();
}