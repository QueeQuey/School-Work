SELECT u.user_ID AS "User ID", u.first_name AS "First Name", u.last_name AS "Last Name"
FROM user AS u
JOIN (
    SELECT reservation.ticket_ticket_id, reservation.user_user_id
    FROM reservation
    JOIN (
        SELECT ticket.ticket_id
        FROM ticket
        WHERE ticket.match_match_id = 'M3'
    ) AS m3Tickets
    ON reservation.ticket_ticket_id = m3Tickets.ticket_id
) AS reservedM3Tickets
ON u.user_id = reservedM3Tickets.user_user_id
LEFT JOIN purchase AS p
ON reservedM3Tickets.ticket_ticket_id = p.ticket_ticket_id
WHERE p.ticket_ticket_id IS NULL;