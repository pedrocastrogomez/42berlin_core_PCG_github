#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content_m;
	t_list	*new_node;
	t_list	*new_head;

	new_head = NULL;
	while (lst != NULL)
	{
		content_m = f(lst->content);
		if (!content_m)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		new_node = ft_lstnew(content_m);
		if (new_node == NULL)
		{
			del(content_m);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}
