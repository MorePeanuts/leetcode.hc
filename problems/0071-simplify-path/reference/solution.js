function simplifyPath(path) {
    const parts = [];
    for (const part of path.split("/")) {
        if (part === "..") {
            parts.pop();
        } else if (part !== "" && part !== ".") {
            parts.push(part);
        }
    }
    return "/" + parts.join("/");
}
