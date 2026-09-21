SELECT `match`.venue_venue_id AS "Venue ID", SUM(ids_2022_tickets.price) AS "Total Price"
FROM `match` 
JOIN (
    SELECT ticket.ticket_id, ticket.price, ticket.match_match_id
    FROM ticket 
    JOIN (
        SELECT ticket_ticket_id
        FROM purchase
        WHERE purchase_date LIKE '2022%'
    ) AS Sold_2022_Tickets
    ON ticket.ticket_id = Sold_2022_Tickets.ticket_ticket_id
) AS ids_2022_tickets
ON `match`.match_id = ids_2022_tickets.match_match_id
GROUP BY `match`.venue_venue_id
ORDER BY `match`.venue_venue_id DESC;