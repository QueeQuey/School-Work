SELECT match_id AS "Match ID", match_kind AS 'Match Kind', venue_venue_id AS "Venue ID", match_date AS "Match Date"
FROM `match`, user, purchase, ticket
WHERE (user.user_id = purchase.user_user_id AND purchase.ticket_ticket_id = ticket.ticket_id AND ticket.match_match_id = `match`.match_id)
	   AND user.first_name = "Jack" AND user.last_name = "Smith"
ORDER BY `match`.match_date DESC;