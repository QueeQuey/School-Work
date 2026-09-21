Select user.user_id AS 'User ID', user.first_name AS 'First Name', user.last_name AS 'Last Name'
FROM user, ticket, purchase
WHERE user.user_id = purchase.user_user_id AND purchase.ticket_ticket_id = ticket.ticket_id
GROUP BY user.user_id
HAVING COUNT(DISTINCT CASE WHEN ticket.type != 'VIP' THEN ticket.type END) = 0;